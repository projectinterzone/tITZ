// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "random.h"

#include "support/cleanse.h"
#ifdef WIN32
#include "compat.h" // for Windows API
#endif
#include "serialize.h"        // for begin_ptr(vec)
#include "util.h"             // for LogPrint()
#include "utilstrencodings.h" // for GetTime()

#include <limits>

#ifndef WIN32
#include <sys/time.h>
#endif

#include <openssl/err.h>
#include <openssl/rand.h>

void GetRandBytes(unsigned char* buf, int num)
{
    if (RAND_bytes(buf, num) != 1) {
        LogPrintf("%s: OpenSSL RAND_bytes() failed with error: %s\n", __func__, ERR_error_string(ERR_get_error(), NULL));
        assert(false);
    }
}

uint32_t insecure_rand_Rz = 11;
uint32_t insecure_rand_Rw = 11;
void seed_insecure_rand(bool fDeterministic)
{
    // The seed values have some unlikely fixed points which we avoid.
    if (fDeterministic) {
        insecure_rand_Rz = insecure_rand_Rw = 11;
    } else {
        uint32_t tmp;
        do {
            GetRandBytes((unsigned char*)&tmp, 4);
        } while (tmp == 0 || tmp == 0x9068ffffU);
        insecure_rand_Rz = tmp;
        do {
            GetRandBytes((unsigned char*)&tmp, 4);
        } while (tmp == 0 || tmp == 0x464fffffU);
        insecure_rand_Rw = tmp;
    }
}

InsecureRand::InsecureRand(bool _fDeterministic)
    : nRz(11),
      nRw(11),
      fDeterministic(_fDeterministic)
{
    // The seed values have some unlikely fixed points which we avoid.
    if(fDeterministic) return;
    uint32_t nTmp;
    do {
        GetRandBytes((unsigned char*)&nTmp, 4);
    } while (nTmp == 0 || nTmp == 0x9068ffffU);
    nRz = nTmp;
    do {
        GetRandBytes((unsigned char*)&nTmp, 4);
    } while (nTmp == 0 || nTmp == 0x464fffffU);
    nRw = nTmp;
}

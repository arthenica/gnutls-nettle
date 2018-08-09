/* rsa-internal.h

   The RSA publickey algorithm.

   Copyright (C) 2001, 2002 Niels Möller

   This file is part of GNU Nettle.

   GNU Nettle is free software: you can redistribute it and/or
   modify it under the terms of either:

     * the GNU Lesser General Public License as published by the Free
       Software Foundation; either version 3 of the License, or (at your
       option) any later version.

   or

     * the GNU General Public License as published by the Free
       Software Foundation; either version 2 of the License, or (at your
       option) any later version.

   or both in parallel, as here.

   GNU Nettle is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received copies of the GNU General Public License and
   the GNU Lesser General Public License along with this program.  If
   not, see http://www.gnu.org/licenses/.
*/

#ifndef NETTLE_RSA_INTERNAL_H_INCLUDED
#define NETTLE_RSA_INTERNAL_H_INCLUDED

#include "nettle-types.h"

#define _rsa_verify _nettle_rsa_verify
#define _rsa_verify_recover _nettle_rsa_verify_recover
#define _rsa_check_size _nettle_rsa_check_size
#define _rsa_blind _nettle_rsa_blind
#define _rsa_unblind _nettle_rsa_unblind

/* Internal functions. */
int
_rsa_verify(const struct rsa_public_key *key,
	    const mpz_t m,
	    const mpz_t s);

int
_rsa_verify_recover(const struct rsa_public_key *key,
		    mpz_t m,
		    const mpz_t s);

size_t
_rsa_check_size(mpz_t n);

/* _rsa_blind and _rsa_unblind are deprecated, unused in the library,
   and will likely be removed with the next ABI break. */
void
_rsa_blind (const struct rsa_public_key *pub,
	    void *random_ctx, nettle_random_func *random,
	    mpz_t c, mpz_t ri) _NETTLE_ATTRIBUTE_DEPRECATED;
void
_rsa_unblind (const struct rsa_public_key *pub, mpz_t c, const mpz_t ri)
  _NETTLE_ATTRIBUTE_DEPRECATED;

#endif /* NETTLE_RSA_INTERNAL_H_INCLUDED */

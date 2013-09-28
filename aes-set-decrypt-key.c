/* aes-set-decrypt-key.c
 *
 * Inverse key setup for the aes/rijndael block cipher.
 */

/* nettle, low-level cryptographics library
 *
 * Copyright (C) 2000, 2001, 2002 Rafael R. Sevilla, Niels Möller
 * Copyright (C) 2013 Niels Möller
 *  
 * The nettle library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or (at your
 * option) any later version.
 * 
 * The nettle library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with the nettle library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02111-1301, USA.
 */

/* Originally written by Rafael R. Sevilla <dido@pacific.net.ph> */

#if HAVE_CONFIG_H
# include "config.h"
#endif

#include "aes-internal.h"

void
aes_invert_key(struct aes_ctx *dst,
	       const struct aes_ctx *src)
{
  _aes_invert (src->rounds, dst->keys, src->keys);
  dst->rounds = src->rounds;
}

void
aes_set_decrypt_key(struct aes_ctx *ctx,
		    size_t keysize, const uint8_t *key)
{
  /* We first create subkeys for encryption,
   * then modify the subkeys for decryption. */
  aes_set_encrypt_key(ctx, keysize, key);
  aes_invert_key(ctx, ctx);
}


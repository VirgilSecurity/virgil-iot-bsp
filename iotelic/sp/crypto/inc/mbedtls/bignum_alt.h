/*
 *  Multi-precision integer library
 *
 *  Copyright (C) 2006-2015, ARM Limited, All Rights Reserved
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  This file is part of mbed TLS (https://tls.mbed.org)
 */

/*
 *  The following sources were referenced in the design of this Multi-precision
 *  Integer library:
 *
 *  [1] Handbook of Applied Cryptography - 1997
 *      Menezes, van Oorschot and Vanstone
 *
 *  [2] Multi-Precision Math
 *      Tom St Denis
 *      https://github.com/libtom/libtommath/blob/develop/tommath.pdf
 *
 *  [3] GNU Multi-Precision Arithmetic Library
 *      https://gmplib.org/manual/index.html
 *
 */

#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#if defined(MBEDTLS_BIGNUM_C)
#include "mbedtls/bignum.h"
#include "mbedtls/bn_mul.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#endif

/*
 * Baseline multiplication: X = A * B  (HAC 14.12)
 */
int
mbedtls_mpi_mul_mpi(mbedtls_mpi *X, const mbedtls_mpi *A, const mbedtls_mpi *B);

/*
 * Modulo: R = A mod B
 */
int
mbedtls_mpi_mod_mpi(mbedtls_mpi *R, const mbedtls_mpi *A, const mbedtls_mpi *B);

/*
 *  * Montgomery multiplication: A = A * B * R^-1 mod N  (HAC 14.36)
 */
int
mpi_montmul(mbedtls_mpi *A, const mbedtls_mpi *B, const mbedtls_mpi *N, mbedtls_mpi_uint mm, const mbedtls_mpi *T);

/*
 * Copyright (c) 2011 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "native_client/src/public/imc_syscalls.h"
// #include "native_client/src/public/imc_types.h"
#include "native_client/src/shared/imc/nacl_imc_c.h"
#include "native_client/src/shared/platform/nacl_error.h"


/* Use the same descriptor number for both:  this demonstrates that the
   two sandboxes have different descriptor tables. */
#define SEND_DESC 3
// #define RECEIVE_DESC 3


void domain1(void) {
  char message[] = "hello";
  // struct NaClAbiNaClImcMsgIoVec iov = { message, strlen(message) };
  // struct NaClAbiNaClImcMsgHdr msg = { &iov, 1, NULL, 0, 0 };
  int sent;

  NaClMessageHeader header;
  NaClIOVec vec;

  vec.base = message;
  vec.length = sizeof(message);
  printf("Size of message: %d\n",sizeof(message));

  /* Test SendDatagram */
  header.iov = &vec;
  header.iov_length = 1;
  header.handles = NULL;
  header.handle_count = 0;
  sent = NaClSendDatagram(SEND_DESC, &header, 0);
  printf("Sending size = %d\n", sent);
  // assert(sent == sizeof buffer);

  printf("In domain 1: Sending message, \"%s\"\n", message);
}

// void domain2(void) {
//   char buffer[100];
//   struct NaClAbiNaClImcMsgIoVec iov = { buffer, sizeof(buffer) - 1 };
//   struct NaClAbiNaClImcMsgHdr msg = { &iov, 1, NULL, 0, 0 };
//   int got = imc_recvmsg(RECEIVE_DESC, &msg, 0);
//   assert(got >= 0);

//   buffer[got] = 0;
//   printf("In domain 2: Received message, \"%s\"\n", buffer);
// }

int main(int argc, char **argv) {
  assert(argc >= 2);
  if (strcmp(argv[1], "domain1") == 0) {
    domain1();
    return 101;
  // } else if (strcmp(argv[1], "domain2") == 0) {
  //   domain2();
  //   return 102;
  } else {
    printf("Unrecognised argument: \"%s\"\n", argv[1]);
  }
  return 0;
}

HTTP web server sandboxed using Google Native Client

How to set up and running the example web server:

1.  Create a subfolder ncserver under native_client/tests/
2.  Clone this repository to native_client/tests/ncserver
3.  In the file native_client/SConstruct, add the following line to nonvariant_tests = [...]:
  'tests/ncserver/nacl.scons',
4.  Copy all of George's server files but main.c to native_client/src/shared/platform
5.  Add the missing *.c files to ative_client/src/shared/platform/build.scons: platform_inputs += [ 'nacl_check.c', 'nacl_global_secure_random.c', 'nacl_host_desc_common.c', 'nacl_interruptible_condvar.c', 'nacl_interruptible_mutex.c', 'nacl_log.c', 'nacl_secure_random_common.c', 'nacl_sync_checked.c', 'nacl_time_common.c', 'platform_init.c', 'refcount_base.cc', 'http.c', 'ncwebserver.c', 'usage.c' ]
6.  Try to run the command "./scons tests/ncserver/ platform=x86-64" in the folder native_client.
7.  You will get some errors because of unused variables. Delete the unused variables so that you can run the command without errors.
8.  Copy the www folder of George's web server into native_client/scons-out/nacl-x86-64/obj/tests/ncserver
9.  Run the example from the directory native_client: "scons-out/nacl-x86-64/obj/tests/ncserver/ncserver scons-out/nacl-x86-64/obj/tests/ncserver/html_parser.nexe -b 127.0.0.1 -p 22334 -d scons-out/nacl-x86-64/obj/tests/ncserver/www"
10.  You should now be able to see a response in your browser when you type in the address bar "localhost:22334"

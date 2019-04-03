# RegisterFooSpn
A simple C++ program to register some SPN against a machine.

In a recent trouble ticket I was helping a customer with I had a situation where our application failed to register the SPN for our service in AD. Due to some reasons I won't go into our application didn't capture the return code from the fialing function call.

The application calls `DsServerRegisterSpn`. This repository is a simple program that adds then removes an SPN but importantly it also prints the return code to stdout.

You need to run this as SYSTEM. I typically accomplish this by using the Mark Russinovich tool [PsExec](https://docs.microsoft.com/en-us/sysinternals/downloads/psexec).

Pop a shell as SYSTEM
```
PsExec.exe -i -s cmd.exe
```

Running it
```
E:\Users\sadawson\bin>RegisterFooSPN.exe
 [+] Attempting to register SPN using DsServerRegisterSpn with ServiceClass set to foo...
   [-] DsServerRegisterSpn to add SPN completed with 0 return code.
 [+] Attempting to deregister SPN using DsServerRegisterSpn with ServiceClass set to foo...
   [-] DsServerRegisterSpn to remove SPN completed with 0 return code.
```
Success 0 return codes for both adding and removing.

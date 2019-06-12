smart_cmd
=========

Pin the smart_cmd.exe to your Windows 7 taskbar and it will open a command prompt at the location
where you currently are in the Windows Explorer.

Download
--------

* [smart_cmd.exe](https://github.com/jhasse/smart_cmd/releases/download/v1.1/smart_cmd.exe) Normal version, uses cmd.exe.

* [smart_powershell.exe](https://github.com/downloads/jhasse/smart_cmd/smart_powershell.exe) Runs the Windows PowerShell (64 bit) instead.

Bugs
----

If smart_cmd.exe doesn't work, please download the Debug build:

* [smart_cmd_debug.exe](https://github.com/jhasse/smart_cmd/releases/download/v1.1/smart_cmd_debug.exe)

When you run it you should see additional output. Please
[fill a bug report](https://github.com/jhasse/smart_cmd/issues/new) and I will try to fix it as soon
as possible.

smart_cmd for MSYS
------------------

If you're using MSYS, you can use
[smart_msys.exe](https://github.com/jhasse/smart_cmd/releases/download/v1.1/smart_msys.exe)
which prints the current path of the Windows Explorer.

Then create a .profile file in your MSYS home folder along with smart_msys.exe
and add:

```
cd "$(./smart_msys.exe)"
```

To pin MSYS to the taskbar use [ConEmu](https://code.google.com/p/conemu-maximus5/).

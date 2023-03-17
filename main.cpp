#include <Windows.h>
#include <vcclr.h>

using namespace System;
using namespace System::Runtime::InteropServices;

typedef void(__stdcall *SpeakDelegate)(const wchar_t*, int);

int main()
{
    // Load the C# DLL
    HMODULE hModule = LoadLibrary("Speech.dll");

    if (hModule != NULL)
    {
        // Get the address of the Speak function in the C# DLL
        SpeakDelegate speak = (SpeakDelegate)GetProcAddress(hModule, "Speak");

        if (speak != NULL)
        {
            // Call the Speak function in the C# DLL
            gcroot<String^> message = "Hello, welcome to North Point Studios!";
            IntPtr ptr = Marshal::StringToHGlobalUni(message);
            speak((const wchar_t*)ptr.ToPointer(), 0);
            Marshal::FreeHGlobal(ptr);

            // Wait for the synthesis to complete before exiting the program
            while (true)
            {
                System::Threading::Thread::Sleep(100);

                // Check if the speech synthesis is complete
                bool complete = true;
                gcroot<Object^> obj = gcnew Object();
                try
                {
                    // Call the IsComplete property in the C# DLL
                    complete = (bool)obj.GetType()->GetProperty("IsComplete")->GetValue(obj, nullptr);
                }
                catch (Exception^ ex)
                {
                    // Log the exception if it occurs
                    System::Diagnostics::Trace::WriteLine(ex->ToString());
                }

                if (complete)
                {
                    break;
                }
            }
        }

        // Unload the C# DLL
        FreeLibrary

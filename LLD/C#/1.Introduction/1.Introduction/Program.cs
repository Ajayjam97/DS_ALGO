using System;
using System.Collections;
using System.IO;
using System.Threading;

namespace _1.Introduction
{
    class Program
    {
        static void Main(string[] args)
        {
            //.Net Framework consists of CLR(Command Language Runtime) & FCL(Framework Class Library)

            //CLR is the runtime environment that runs the codes & helps in making development process easier by providing  
            //services like remoting, thread management, type-safety etc.

            //CLR further contains CLI(Command Language Infrastructure), GC(Garbage Collector) & JIT(Just In Time compiler)

            //FCL is a collection of reusable, object-oriented class libraries and methods, etc that can be integrated with CLR. 

            //Namespaces in FCL are a group of related classes and interfaces that can be used by all .NET supported languages.
            //Ex: System, System.Collections, System.IO, System.Threading etc

            //Execution Process of CLR : Source code > MSIL(Microsoft Integrated Language) code > Object/Executable
            //Stages of code           : C# code     > Compiletime (Language specific compiler) > Runtime (JIT)

            //Managed Vs Unmanaged code
            //Managed code executed by a managed runtime environment. Pointers can not be used in managed code because of GC.
            //Unmanaged code executed directly by OS. Unsafe code provides the flexibilty to use pointers.

            unsafe{
                int var = 20;
                int* p = &var;

                Console.WriteLine("Value of *p is: {0}", *p);
            }

            //Some differences in C# & Java

            //C# supports operator overloading & Java does not.
            //C# has CLR & Java has JVM.
            //C# doesnot supports checked exceptions & Java supports both checked, unchecked exceptions.
            //C# supports structure, Union & Java doesnot supports both.


            //Features of C#:
            //Simple, Modern, Consistent, Object Oriented, Type Safe, Compatible, Interoperable.
        }
    }
}

using System;
using System.Text;

namespace _3.Basics
{
    public enum Days
    {
        None      = 0,  // 0
        Monday    = 1,  // 1
        Tuesday   = 2,  // 2
        Wednesday = 3,  // 3
        Thursday  = 4,  // 4
        Friday    = 5,  // 5
        Saturday  = 6,  // 6
        Sunday    = 7  // 7
    }

    class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine("Hello World!");

            System.Boolean  @boolean = true;     Console.WriteLine("Value of boolean: {0}", @boolean);//bool      
            System.Char      @char = 'a';         Console.WriteLine("Value of char: {0}", @char);//char
            System.SByte    @sbyte = -128;          Console.WriteLine("Value of sbyte: {0}", @sbyte);//sbyte
            System.Byte     @byte = 255;           Console.WriteLine("Value of byte: {0}", @byte);//byte
            System.Int16    @int16 = 1;          Console.WriteLine("Value of short: {0}", @int16);//short
            System.Int32    @int32 = 1;          Console.WriteLine("Value of int: {0}", @int32);//int
            System.Decimal   @dec = Decimal.One/3*3;   Console.WriteLine("Value of decimal: {0}", Math.Round(@dec,2));//decimal
            System.Single    @float =  1/3f;    Console.WriteLine("Value of float: {0}", @float);//float
            System.Double    @double = 1/3.0;   Console.WriteLine("Value of double: {0}", @double);//double
            
            System.Object    @object = "Boy"; Console.WriteLine("Value of Object: {0}", @object);//Object
            System.String    @string = "ImmutableString"; Console.WriteLine("Value of Object: {0}", @string);//String
            System.Text.StringBuilder    @stringbuilder = new StringBuilder("MutableString"); Console.WriteLine("Value of Object: {0}", @stringbuilder);//String
    
            Days @monday = Days.Monday;     Console.WriteLine("Value of Object: {0}", (int)@monday);//Enum

            //Boxing Vs Unboxing
            int num=23;
            object obj = num;   Console.WriteLine("Value of obj: {0}", obj);//Boxing
            int i = (int) obj;  Console.WriteLine("Value of i: {0}", i);//Unboxing

        }
    }
}

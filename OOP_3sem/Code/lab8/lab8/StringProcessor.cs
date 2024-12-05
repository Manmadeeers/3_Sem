using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab8
{
    public static class StringProcessor
    {
        static StringProcessor() { }

        public static string DeletePunktuation(string ProcessedString)
        {

            return new string(ProcessedString.Where(c=>!char.IsPunctuation(c)).ToArray());
        }

        public static string BringToUpper(string ProcessedString)
        {
            return ProcessedString.ToUpper();
        }

        public static string BringToLower(string ProcessedString)
        {
            return ProcessedString.ToLower();
        }

        public static string TrimExtraSpaces(string input)
        {
            return string.Join(" ", input.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries));
        }

        public static string Reverse(string input)
        {
            char[] charArray = input.ToCharArray();
            Array.Reverse(charArray);
            return new string(charArray);
        }

    }
}

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class _2016QualD
{
    static void reverse(int end, char[] S)
    {
        int begin = 0;
        while(begin < end)
        {
            var tmp = S[begin];
            S[begin] = S[end] == '+' ? '-' : '+';
            S[end]  = tmp == '+' ? '-' : '+';
            ++begin;
            --end;
        }
        if (begin == end)
            S[begin] = S[begin] == '+' ? '-' : '+';
    }

    public static void Main(string[] args)
    {
        using (var reader = new StreamReader("../../B.in"))
        using (var writer = new StreamWriter("../../B.out"))
        {
            int T = int.Parse(reader.ReadLine());
            for (int icase = 1; icase <= T; ++icase)
            {
                var S = reader.ReadLine().ToCharArray();
                int res = 0;

                int end = S.Length - 1;
                while (true)
                {
                    while (end >= 0 && S[end] == '+')
                        --end;
                    if (end < 0)
                        break;
                    int begin = 0;                 
                    while (begin < S.Length && S[begin] == '+')
                        ++begin;                   
                    ++res;
                    if (begin > 0)
                        reverse(begin - 1, S);
                    else
                        reverse(end, S);
                }

                writer.WriteLine(string.Format("Case #{0}: {1}", icase, res));
            }

        }
    }
}


using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

class _2016QualD
{
    static List<int> prime;

    static BigInteger convertBase(UInt32 n, int b)
    {
        BigInteger res = 0;
        checked
        {
            for (int m = 31; m >= 0; --m)
            {
                res *= b;
                if (((n >> m) & 1) != 0)
                {
                    res += 1;
                }
            }
        }
        return res;
    }

    static int findDiv(BigInteger n)
    {
        checked
        {
            for (int i = 0; i < prime.Count && prime[i] < n; ++i)
                if (n % prime[i] == 0)
                    return prime[i];
            return -1;
        }
    }

    public static void Main(string[] args)
    {
        int N = 32;
        int J = 500;

        prime = new List<int>();
        {
            var p = new bool[1000000];
            for (int i = 0; i < p.Length; ++i)
                p[i] = true;
            p[0] = p[1] = false;
            for (int i = 2; i < p.Length; ++i)
                if (p[i])
                {
                    prime.Add(i);
                    for (int j = i + i; j < p.Length; j += i)
                        p[j] = false;
                }
        }

        using (var writer = new StreamWriter("../../C.out"))
        {
            writer.WriteLine("Case #1:");
            var div = new int[9];
            for (UInt32 tmp = (1u << N - 1) + 1; J > 0; tmp += 2)
            {
                bool valid = true;
                for (int b = 2; b <= 10; ++b)
                {
                    var curr = convertBase(tmp, b);
                    div[b - 2] = findDiv(curr);
                    if (div[b - 2] == -1)
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    --J;
                    writer.WriteLine(Convert.ToString(tmp, 2) + " " + string.Join(" ", div.Select(n => n.ToString())));
                }
            }
        }
    }
}


using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class _2016QualD
{


    public static void Main(string[] args)
    {
        using (var reader = new StreamReader("../../A.in"))
        using (var writer = new StreamWriter("../../A.out"))
        {
            int T = int.Parse(reader.ReadLine());
            for (int icase = 1; icase <= T; ++icase)
            {
                var line = reader.ReadLine();
                var res = line[0].ToString();

                for (int i = 1; i < line.Length; ++i)
                    if (line[i] < res[0])
                        res = res + line[i];
                    else
                        res = line[i] + res;

                writer.WriteLine(string.Format("Case #{0}: " + res, icase));

            }

        }
    }
}


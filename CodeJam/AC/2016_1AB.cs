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
        using (var reader = new StreamReader("../../B.in"))
        using (var writer = new StreamWriter("../../B.out"))
        {
            int T = int.Parse(reader.ReadLine());
            for (int icase = 1; icase <= T; ++icase)
            {
                var N = int.Parse(reader.ReadLine());
                var h = new Dictionary<int, int>();

                for (int i = 0; i < 2 * N - 1; ++i)
                {
                    var t = reader.ReadLine().Split(' ').Select(s => int.Parse(s));
                    foreach (var key in t)
                    {
                        if (!h.ContainsKey(key))
                            h.Add(key, 0);
                        ++h[key];
                    }
                }

                var res = h.Where(p => p.Value % 2 == 1).Select(p => p.Key).OrderBy(p => p);

                writer.Write(string.Format("Case #{0}: ", icase));
                writer.WriteLine(string.Join(" ", res.Select(s => s.ToString())));
            }

        }
    }
}


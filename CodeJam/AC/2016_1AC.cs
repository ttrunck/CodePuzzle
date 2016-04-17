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
        using (var reader = new StreamReader("../../C.in"))
        using (var writer = new StreamWriter("../../C.out"))
        {
            int T = int.Parse(reader.ReadLine());
            for (int icase = 1; icase <= T; ++icase)
            {
                int N = int.Parse(reader.ReadLine());
                var line = reader.ReadLine().Split(' ');
                var t = new int[N];
                for (int i = 0; i < N; ++i)
                    t[i] = int.Parse(line[i]) - 1;

                int res = 0;

                // Check for cycle
                for (int i = 0; i < N; ++i)
                {
                    var S = new HashSet<int>();
                    int curr = i;
                    S.Add(i);
                    while (!S.Contains(t[curr]))
                    {
                        curr = t[curr];
                        S.Add(curr);
                    }
                    if (t[curr] == i)
                        res = Math.Max(res, S.Count);
                }

                // Check for 2-Cycle and pending edges
                var rt = new List<int>[N];
                for (int i = 0; i < N; ++i)
                    rt[i] = new List<int>();
                for (int i = 0; i < N; ++i)
                    rt[t[i]].Add(i);

                int tmp = 0;
                for (int i = 0; i < N; ++i)
                    if (t[t[i]] == i)
                    {
                        tmp += 2;
                        int l = 0;
                        foreach (var x in rt[i])
                        {
                            if (x == t[i]) continue;
                            l = Math.Max(l, height(x, rt));
                        }

                        int r = 0;
                        foreach (var x in rt[t[i]])
                        {
                            if (x == i) continue;
                            r = Math.Max(r, height(x, rt));
                        }
                        tmp += l + r;
                    }

                res = Math.Max(res, tmp/2);

                writer.WriteLine(string.Format("Case #{0}: {1}", icase, res));
            }

        }
    }

    private static int height(int i, List<int>[] rt)
    {
        int h = 1;
        foreach (var x in rt[i])
            h = Math.Max(h, 1 + height(x, rt));
        return h;
    }
}


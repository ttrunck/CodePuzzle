using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;


public class SuccessfulMerger
{
    int N;
    HashSet<int>[] g;
    int[] p;
    HashSet<int> h;

    bool cycle(int pred, int v)
    {
        foreach (int u in g[v])
        {
            if (u == pred) continue;
            if (p[u] != -1)
            {
                do
                {
                    h.Add(v);
                    v = p[v];
                } while (v != u);
                return true;
            }
            else
            {
                p[u] = v;
                if (cycle(v, u))
                    return true;
            }
        }
        return false;
    }

    public int minimumMergers(int[] road)
    {
        N = road.Length;
        g = new HashSet<int>[N];

        for (int i = 0; i < N; ++i)
            g[i] = new HashSet<int>();
        for (int i = 0; i < N; ++i)
        {
            g[i].Add(road[i]);
            g[road[i]].Add(i);
        }

        int res = N - 1;

        p = new int[N];
        for (int i = 0; i < N; ++i)
            p[i] = -1;
        h = new HashSet<int>();
        p[0] = 0;
        cycle(0, 0);

        for (int i = 0; i < N; ++i)
            if (g[i].Count == 1)
                --res;
        foreach (int x in h)
            if (g[x].Count == 2)
            {
                --res;
                break;
            }

        return Math.Max(0, res);
    }

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
#region Testing code generated by KawigiEdit
[STAThread]
private static Boolean KawigiEdit_RunTest(int testNum, int[] p0, Boolean hasAnswer, int p1)
{
    Console.Write("Test " + testNum + ": [" + "{");
    for (int i = 0; p0.Length > i; ++i)
    {
        if (i > 0)
        {
            Console.Write(",");
        }
        Console.Write(p0[i]);
    }
    Console.Write("}");
    Console.WriteLine("]");
    SuccessfulMerger obj;
    int answer;
    obj = new SuccessfulMerger();
    DateTime startTime = DateTime.Now;
    answer = obj.minimumMergers(p0);
    DateTime endTime = DateTime.Now;
    Boolean res;
    res = true;
    Console.WriteLine("Time: " + (endTime - startTime).TotalSeconds + " seconds");
    if (hasAnswer)
    {
        Console.WriteLine("Desired answer:");
        Console.WriteLine("\t" + p1);
    }
    Console.WriteLine("Your answer:");
    Console.WriteLine("\t" + answer);
    if (hasAnswer)
    {
        res = answer == p1;
    }
    if (!res)
    {
        Console.WriteLine("DOESN'T MATCH!!!!");
    }
    else if ((endTime - startTime).TotalSeconds >= 2)
    {
        Console.WriteLine("FAIL the timeout");
        res = false;
    }
    else if (hasAnswer)
    {
        Console.WriteLine("Match :-)");
    }
    else
    {
        Console.WriteLine("OK, but is it right?");
    }
    Console.WriteLine("");
    return res;
}
public static void Main(string[] args)
{
    Boolean all_right;
    all_right = true;

    int[] p0;
    int p1;

    // ----- test 0 -----
    p0 = new int[] { 2, 2, 1, 1, 1 };
    p1 = 1;
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------

    // ----- test 1 -----
    p0 = new int[] { 3, 4, 5, 4, 5, 3 };
    p1 = 2;
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------

    // ----- test 2 -----
    p0 = new int[] { 1, 0, 1, 0, 0, 0, 1, 0, 1, 1 };
    p1 = 1;
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------

    // ----- test 3 -----
    p0 = new int[] { 1, 2, 3, 0 };
    p1 = 2;
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
    // ------------------

    // ----- test 4 -----
    p0 = new int[] { 31, 19, 0, 15, 30, 32, 15, 24, 0, 20, 40, 1, 22, 21, 39, 28, 0, 23, 15, 5, 19, 22, 6, 32, 8, 38, 35, 30, 4, 28, 32, 18, 18, 9, 22, 41, 20, 18, 6, 25, 41, 34, 4 };
    p1 = 25;
    all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
    // ------------------

    // ----- test 5 -----
    p0 = new int[] { 1, 0 };
    p1 = 0;
    all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
    // ------------------

    if (all_right)
    {
        Console.WriteLine("You're a stud (at least on the example cases)!");
    }
    else
    {
        Console.WriteLine("Some of the test cases had errors.");
    }
    Console.ReadKey();
}
    #endregion
    // END KAWIGIEDIT TESTING
}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

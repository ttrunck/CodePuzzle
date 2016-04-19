using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

public class MoveStones
{
    public long get(int[] a, int[] b)
    {
        int n = a.Length;
        var t = new long[n];
        for (int i = 0; i < n; ++i)
            t[i] = a[i] - b[i];

        if (t.Sum() != 0)
            return -1;

        long res = long.MaxValue;

        for (int start = 0; start < n; ++start)
        {
            long val = 0;
            long curr = t[start];
            for (int i = (start + 1) % n; i != start; i = (i + 1) % n)
            {
                val += Math.Abs(curr);
                curr += t[i];
            }
            res = Math.Min(res, val);
        }
        return res;
    }

    // BEGIN KAWIGIEDIT TESTING
    // Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
    #region Testing code generated by KawigiEdit
    [STAThread]
    private static Boolean KawigiEdit_RunTest(int testNum, int[] p0, int[] p1, Boolean hasAnswer, long p2)
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
        Console.Write("}" + "," + "{");
        for (int i = 0; p1.Length > i; ++i)
        {
            if (i > 0)
            {
                Console.Write(",");
            }
            Console.Write(p1[i]);
        }
        Console.Write("}");
        Console.WriteLine("]");
        MoveStones obj;
        long answer;
        obj = new MoveStones();
        DateTime startTime = DateTime.Now;
        answer = obj.get(p0, p1);
        DateTime endTime = DateTime.Now;
        Boolean res;
        res = true;
        Console.WriteLine("Time: " + (endTime - startTime).TotalSeconds + " seconds");
        if (hasAnswer)
        {
            Console.WriteLine("Desired answer:");
            Console.WriteLine("\t" + p2);
        }
        Console.WriteLine("Your answer:");
        Console.WriteLine("\t" + answer);
        if (hasAnswer)
        {
            res = answer == p2;
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
        int[] p1;
        long p2;

        // ----- test 0 -----
        p0 = new int[] { 12 };
        p1 = new int[] { 12 };
        p2 = 0L;
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------

        // ----- test 1 -----
        p0 = new int[] { 10 };
        p1 = new int[] { 9 };
        p2 = -1L;
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------

        // ----- test 2 -----
        p0 = new int[] { 0, 5 };
        p1 = new int[] { 5, 0 };
        p2 = 5L;
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------

        // ----- test 3 -----
        p0 = new int[] { 1, 2, 3 };
        p1 = new int[] { 3, 1, 2 };
        p2 = 2L;
        all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
        // ------------------

        // ----- test 4 -----
        p0 = new int[] { 1, 0, 1, 1, 0 };
        p1 = new int[] { 0, 3, 0, 0, 0 };
        p2 = 4L;
        all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
        // ------------------

        // ----- test 5 -----
        p0 = new int[] { 1000000000, 0, 0, 0, 0, 0 };
        p1 = new int[] { 0, 0, 0, 1000000000, 0, 0 };
        p2 = 3000000000L;
        all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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
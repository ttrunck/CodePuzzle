using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;


public class SmilesTheFriendshipUnicorn
{
    List<int>[] g;
    int N;

    bool dfs(int i, HashSet<int> seen)
    {
        if (seen.Count == 5) return true;
        foreach (int x in g[i])
            if (!seen.Contains(x))
            {
                seen.Add(x);
                if (dfs(x, seen))
                    return true;
                seen.Remove(x);
            }
        return false;
    }

    public string hasFriendshipChain(int N, int[] A, int[] B)
    {
        this.N = N;
        g = new List<int>[N];
        for (int i = 0; i < N; ++i)
            g[i] = new List<int>();
        for (int i = 0; i < A.Length; ++i)
        {
            g[A[i]].Add(B[i]);
            g[B[i]].Add(A[i]);
        }

        for (int i = 0; i < N; ++i)
        {
            var seen = new HashSet<int> { i };
            if (dfs(i, seen))
                return "Yay!";
        }

        return ":(";
    }

    // BEGIN KAWIGIEDIT TESTING
    // Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
    #region Testing code generated by KawigiEdit
    [STAThread]
    private static Boolean KawigiEdit_RunTest(int testNum, int p0, int[] p1, int[] p2, Boolean hasAnswer, string p3)
    {
        Console.Write("Test " + testNum + ": [" + p0 + "," + "{");
        for (int i = 0; p1.Length > i; ++i)
        {
            if (i > 0)
            {
                Console.Write(",");
            }
            Console.Write(p1[i]);
        }
        Console.Write("}" + "," + "{");
        for (int i = 0; p2.Length > i; ++i)
        {
            if (i > 0)
            {
                Console.Write(",");
            }
            Console.Write(p2[i]);
        }
        Console.Write("}");
        Console.WriteLine("]");
        SmilesTheFriendshipUnicorn obj;
        string answer;
        obj = new SmilesTheFriendshipUnicorn();
        DateTime startTime = DateTime.Now;
        answer = obj.hasFriendshipChain(p0, p1, p2);
        DateTime endTime = DateTime.Now;
        Boolean res;
        res = true;
        Console.WriteLine("Time: " + (endTime - startTime).TotalSeconds + " seconds");
        if (hasAnswer)
        {
            Console.WriteLine("Desired answer:");
            Console.WriteLine("\t" + "\"" + p3 + "\"");
        }
        Console.WriteLine("Your answer:");
        Console.WriteLine("\t" + "\"" + answer + "\"");
        if (hasAnswer)
        {
            res = answer == p3;
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

        int p0;
        int[] p1;
        int[] p2;
        string p3;

        // ----- test 0 -----
        p0 = 5;
        p1 = new int[] { 0, 1, 2, 3 };
        p2 = new int[] { 1, 2, 3, 4 };
        p3 = "Yay!";
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
        // ------------------

        // ----- test 1 -----
        p0 = 5;
        p1 = new int[] { 0, 1, 2, 3, 1 };
        p2 = new int[] { 1, 2, 3, 0, 4 };
        p3 = "Yay!";
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
        // ------------------

        // ----- test 2 -----
        p0 = 6;
        p1 = new int[] { 0, 0, 0, 0, 0 };
        p2 = new int[] { 1, 2, 3, 4, 5 };
        p3 = ":(";
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
        // ------------------

        // ----- test 3 -----
        p0 = 8;
        p1 = new int[] { 1, 3, 4, 3, 4, 3, 0, 2 };
        p2 = new int[] { 7, 7, 7, 4, 6, 5, 4, 7 };
        p3 = "Yay!";
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
        // ------------------

        // ----- test 4 -----
        p0 = 7;
        p1 = new int[] { 0, 1, 1, 5, 4, 5 };
        p2 = new int[] { 5, 2, 3, 6, 1, 1 };
        p3 = ":(";
        all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
        // ------------------

        // ----- test 5 -----
        p0 = 42;
        p1 = new int[] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41 };
        p2 = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 0 };
        p3 = "Yay!";
        all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
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

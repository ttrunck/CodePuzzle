using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;


public class CliqueParty
{
    public int maxsize(int[] tt, int kk)
    {
        int n = tt.Length;
        var t = new long[n];
        for (int i = 0; i < n; ++i)
            t[i] = tt[i];
        long k = kk;
        Array.Sort(t);

        int res = 2;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n ; ++j)
                for (int m = j+1; m < n ; ++m)
                {
                    int curr = 1;
                    long last = t[i];
                    long mini = t[m] - t[j];
                    long maxi = k * mini;
                    for (int l = i + 1; l < n; ++l)
                        if (t[l] - t[i] <= maxi && t[l] - last >= mini)
                        {
                            last = t[l];
                            ++curr;
                        }
                    res = Math.Max(res, curr);
                }

        return res;
    }

    // BEGIN KAWIGIEDIT TESTING
    // Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
    #region Testing code generated by KawigiEdit
    [STAThread]
    private static Boolean KawigiEdit_RunTest(int testNum, int[] p0, int p1, Boolean hasAnswer, int p2)
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
        Console.Write("}" + "," + p1);
        Console.WriteLine("]");
        CliqueParty obj;
        int answer;
        obj = new CliqueParty();
        DateTime startTime = DateTime.Now;
        answer = obj.maxsize(p0, p1);
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
        int p1;
        int p2;

        // ----- test 0 -----
        p0 = new int[] { 1, 2, 3 };
        p1 = 2;
        p2 = 3;
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------

        // ----- test 1 -----
        p0 = new int[] { 1, 2, 3 };
        p1 = 1;
        p2 = 2;
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------

        // ----- test 2 -----
        p0 = new int[] { 4, 10, 5, 6 };
        p1 = 2;
        p2 = 3;
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------

        // ----- test 3 -----
        p0 = new int[] { 1, 2, 3, 4, 5, 6 };
        p1 = 3;
        p2 = 4;
        all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
        // ------------------

        // ----- test 4 -----
        p0 = new int[] { 10, 9, 25, 24, 23, 30 };
        p1 = 7;
        p2 = 4;
        all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
        // ------------------

        p0 = new int[] { 770593492, 834911005, 393930861, 921957561, 893995750, 644957042, 661423555, 885964471, 77911800, 821760017, 131791896 };
        p1 = 5;
        p2 = 4;
        all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;

        p0 = new int[] { 9866, 10959, 4025, 19306, 17437, 19043, 13713, 16895, 8918, 5769, 3250, 20410, 15284, 3515, 7016, 1143, 15788, 12092, 8096, 2041, 11325, 9220, 16496, 1413, 8502, 12299, 383, 4711, 13295, 13468, 10747, 2875, 21361 };
        p1 = 2;
        p2 = 3;
        all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;

        p0 = new int[] { 21827, 19305, 475, 18213, 13904, 28345, 10170, 1135, 22552, 30474, 22298, 14128, 30579, 18380, 6235, 16707, 26459, 2922, 24886, 26966, 5515 };
        p1 = 440486036;
        p2 = 21;
        all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;

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

using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;


public class AlmostFibonacciKnapsack
{
	public int[] getIndices(long x)
	{
        var A = new List<long> { 2, 3 };
        while(A.Last() <= x)
        {
            A.Add(A[A.Count - 1] + A[A.Count - 2] - 1);
        }

        var res = new List<int>();
        for(int i=A.Count-1;i>=0 && x>0;--i)
            if (A[i] == x || x > A[i] + 1)
            {
                res.Add(i + 1);
                x -= A[i];
            }

        return res.ToArray();
	}

	// BEGIN KAWIGIEDIT TESTING
	// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
	#region Testing code generated by KawigiEdit
	[STAThread]
	private static Boolean KawigiEdit_RunTest(int testNum, long p0, Boolean hasAnswer, int[] p1) {
		Console.Write("Test " + testNum + ": [" + p0);
		Console.WriteLine("]");
		AlmostFibonacciKnapsack obj;
		int[] answer;
		obj = new AlmostFibonacciKnapsack();
		DateTime startTime = DateTime.Now;
		answer = obj.getIndices(p0);
		DateTime endTime = DateTime.Now;
		Boolean res;
		res = true;
		Console.WriteLine("Time: " + (endTime - startTime).TotalSeconds + " seconds");
		if (hasAnswer) {
			Console.WriteLine("Desired answer:");
			Console.Write("\t" + "{");
			for (int i = 0; p1.Length > i; ++i) {
				if (i > 0) {
					Console.Write(",");
				}
				Console.Write(p1[i]);
			}
			Console.WriteLine("}");
		}
		Console.WriteLine("Your answer:");
		Console.Write("\t" + "{");
		for (int i = 0; answer.Length > i; ++i) {
			if (i > 0) {
				Console.Write(",");
			}
			Console.Write(answer[i]);
		}
		Console.WriteLine("}");
		if (hasAnswer) {
			if (answer.Length != p1.Length) {
				res = false;
			} else {
				for (int i = 0; answer.Length > i; ++i) {
					if (answer[i] != p1[i]) {
						res = false;
					}
				}
			}
		}
		if (!res) {
			Console.WriteLine("DOESN'T MATCH!!!!");
		} else if ((endTime - startTime).TotalSeconds >= 2) {
			Console.WriteLine("FAIL the timeout");
			res = false;
		} else if (hasAnswer) {
			Console.WriteLine("Match :-)");
		} else {
			Console.WriteLine("OK, but is it right?");
		}
		Console.WriteLine("");
		return res;
	}
	public static void Main(string[] args) {
		Boolean all_right;
		all_right = true;
		
		long p0;
		int[] p1;
		
		// ----- test 0 -----
		p0 = 148L;
		p1 = new int[]{6,10,8,5};
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
		// ------------------
		
		// ----- test 1 -----
		p0 = 2L;
		p1 = new int[]{1};
		all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
		// ------------------
		
		// ----- test 2 -----
		p0 = 13L;
		p1 = new int[]{2,3,4};
		all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
		// ------------------
		
		// ----- test 3 -----
		p0 = 3L;
		p1 = new int[]{2};
		all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
		// ------------------
		
		// ----- test 4 -----
		p0 = 86267769395L;
		p1 = new int[]{3,14,15,9,26,53,5,8};
		all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
		// ------------------
		
		if (all_right) {
			Console.WriteLine("You're a stud (at least on the example cases)!");
		} else {
			Console.WriteLine("Some of the test cases had errors.");
		}
        Console.ReadKey();
	}
	#endregion
	// END KAWIGIEDIT TESTING
}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

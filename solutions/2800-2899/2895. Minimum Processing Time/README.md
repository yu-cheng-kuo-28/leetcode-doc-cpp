<p><strong>Problem:</strong> [2895. Minimum Processing Time](https://leetcode.com/problems/minimum-processing-time/)<br>
<strong>Category:</strong> Array <br>
<strong>Difficulty:</strong> Medium <br>
<strong>Language:</strong> C++ </p>

[1] Time Complexity: O(N log N + M log M + P)

[2] Space Complexity: O(log N + log M)

Where N is the size of processorTime, M is the size of tasks, and P is the number of processors (size of processorTime) 

<br>

<h4>(1) Thought Process</h4>

It's a problem I encountered at a OA of a big tech. Though this problem seems complicated, the solution is actually quite intuitive. Just assign the longest task to the earliest processor avaliable iteratively.
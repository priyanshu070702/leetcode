# Pairwise swap elements of a linked list
## Easy
<div class="problems_problem_content__Xm_eO" style="user-select: auto;"><p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Given a singly linked list of size <strong style="user-select: auto;">N</strong>. The task is to swap elements in the linked list pairwise.<br style="user-select: auto;">For example, if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.<br style="user-select: auto;"><strong style="user-select: auto;">Note</strong>: You need to swap the nodes, not only the data. If only data is swapped then driver will print -1.</span></p>
<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></span></p>
<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
</strong>LinkedList: 1-&gt;2-&gt;2-&gt;4-&gt;5-&gt;6-&gt;7-&gt;8
<strong style="user-select: auto;">Output: <br style="user-select: auto;"></strong>2&nbsp;1&nbsp;4&nbsp;2&nbsp;6&nbsp;5&nbsp;8&nbsp;7<strong style="user-select: auto;">
Explanation: <br style="user-select: auto;"></strong>After swapping each pair considering (1,2), (2, 4), (5, 6).. so on as pairs, we get 2, 1, 4, 2, 6, 5, 8, 7 as a new linked list.</span>
</pre>
<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></span></p>
<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
</strong>LinkedList: 1-&gt;3-&gt;4-&gt;7-&gt;9-&gt;10-&gt;1
<strong style="user-select: auto;">Output: <br style="user-select: auto;"></strong>3&nbsp;1&nbsp;7&nbsp;4&nbsp;10&nbsp;9&nbsp;1<strong style="user-select: auto;">
Explanation: <br style="user-select: auto;"></strong>After swapping each pair considering (1,3), (4, 7), (9, 10).. so on as pairs, we get 3, 1, 7, 4, 10, 9, 1 as a new linked list.</span></pre>
<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Your Task:</strong><br style="user-select: auto;">The task is to complete the function&nbsp;<strong style="user-select: auto;">pairWiseSwap</strong>() which takes the head node as the only argument and returns the head of modified linked list.</span></p>
<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Expected Time Complexity:&nbsp;</strong>O(N).<br style="user-select: auto;"><strong style="user-select: auto;">Expected Auxiliary Space:&nbsp;</strong>O(1).</span></p>
<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Constraints:</strong><br style="user-select: auto;">1 ≤ N ≤&nbsp;10<sup style="user-select: auto;">5</sup></span></p></div>
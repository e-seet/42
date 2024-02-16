# TO DO

Stack A: 3 items
Stack B: 2 items
Noteworthy: In stack B, it will always be A>B or B > A given that there is only 2 items

Given the current code:

Figure out when do we / should we push
Half rotate and half push back

## Trying now

algo 1:
Step 1: We push the smallest number we can see from the 3. [top, bot next]. Rotate if required and push
Step 2: We push the smallest number we can see from the 3. [top, bot next].  Rotate if required and push
Step 3: Rotate the 3 elements and 2 elements.
step 4: push back.

<!-- 1.Try and see how many does the sorting stack A and B before putting it back takes [Don't Work]

- Optimised by having it rotate at the same time when sorting the stack.
- To arrange it back.
- Issue: May not be 8 steps as 1. We need to slide back into stack a from stack b, which will take a lot of steps

2.Try and see if we can Take top 2 of the stack and push back even before we finish sorting both of the stack. Aka half rotate and half push back

- Technically speaking, after pushing the top 2, whatever operations we do to rotate on stack a, will just change the position of stack b if we need to. Therefore, we should do a partial check and partial push back.

- it is possible because in the stack of 3, we have the top, bottom and center value. This means that we have data on the whole stack and is able to do sort acccordingly.

3.See if figuring out the smallest two will help.

So 3 ways to try:
1.Just push top 2 items of stack a [now]. Then half rotate and half push back
2.Check before pushing to stack. [top, bot, sec]
<!-- 3.Push top 2 -->

Current trying:
<!-- Push top 2, then we sort and push back half half. -->
Come up with rule to push it. Why do we need to push? When do we need to push?
2.Try and see if we can use scan top two before pushing to stack and only push top two to stack if possible

- One of the most workable test case: top 2 are the smallest. Definitely will be able to sort within 8 steps -->
<!-- We try grabbing: 1 5 -->
<!-- We try grabbing: 1 2 -->
<!-- We try grabbing: 4 5 -->

For now we try this method:
Check top, bot and next. Grab the one with the smallest number

1. Grab top of stack.

case 1: Top of stack is 1 or 5.

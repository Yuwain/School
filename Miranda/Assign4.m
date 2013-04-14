|| INDIVIDUAL ASSIGNMENT #4 - Worth twice the marks of other assignments

|| SUBMIT a printout of your program, and DEMONSTRATE your program at the 
|| group labs on Thursday 20th or Friday 21st October

|| A)  Download this file and use it as part of your program. Note that
|| if you download the file onto a PC, you can edit it using WordPad and then 
|| upload using SSH. However,remember to change the upload settings on SSH
|| as described in the linked document on the course website.

|| The URL of this file is 
||    http://cs.uwindsor.ca/~richard/60_100/indiv_assignments/indiv_assig_4.m

|| B) Complete the following

|| Your name is                 : Jeremy High
|| your 60-100 section number is: 01

|| C) Read through the following is the data

male   = ["doug",   "paul", "bill", "simon", "james"]
female = ["angela", "sue",  "mary", "beth", "anne", "cathy"]

parent_of = [("doug", "paul") , ("doug", "sue") ,   ("paul", "cathy"),
             ("paul", "james"), ("sue", "simon") ,  ("sue", "mary"),
             ("mary", "bill") , ("bill", "angela"), ("angela", "beth"),
             ("anne", "cathy")] 
                        
	     
married_to =  [("anne", "paul"), ("paul", "anne")]

|| The following are example programs for relational algebra operators
	    
project_first_of_2 r           = mkset[(x) | (x, y) <- r]
project_second_of_2 r          = mkset[(y) | (x, y) <- r]
project_first_and_third_of_3 r = mkset[(x,z) | (x,y,z) <- r]
select_first_of_2 r key        = [(x,y) | (x, y) <- r; x = key]
join_second_of_2_with_first_of_2 r s
                 = [(x, y, z) | (x, y) <- r; (a , z) <- s; y = a]
      
union        s t = s ++ (t --s)
intersection s t = s -- (s -- t)

make_transitive [] = []
make_transitive ((x, y):ps)
  = new_direct_paths ++
    [(a,c) | (a,b) <- mtps; (d,c) <- new_direct_paths; b = d] ++ mtps
    where mtps = make_transitive ps
          new_direct_paths = (x, y):[(x, b) | (n, b) <- mtps; n = y]

|| D) Now compile this file and try each of the following commands 
|| at the Miranda prompt

||  union male female
||  project_first_of_2 parent_of
||  select_first_of_2 parent_of "paul"
||  project_second_of_2 parent_of
||  join_second_of_2_with_first_of_2 parent_of parent_of

    
|| E) You are now to define the following relations in terms of the 
|| relations male, female and parent_of, and the relational operators
|| from the above, or similar to them (which you can define yourself)

|| For example, the grandparent relation can be defined by
|| joining parent_of with itself, using 
||         join_second_of_2_with_first_of_2  and then use 
||                                       project_first_and_third_of_3
|| The answer for this relation is:
   
grandparent = project_first_and_third_of_3 (join_second_of_2_with_first_of_2 parent_of parent_of)

|| Now try to do the following yourself

join_first_of_2_with_first_of_2 s t = [(x,y,z) | (x,y) <- s; (w,z) <- t; w = x]
project_second_and_third_of_3 r = [(y,z) | (x,y,z) <- r]
swap r = [(y,x) | (x,y) <- r]
child_of = swap parent_of
select_second_of_2 r key = [(x,y) | (x,y) <- r; y = key]
join_first_of_1_with_first_of_2 r s = [(x,y) | (w) <- r; (x,y) <- s; x = w]
neice_or_nephew = swap aunty_or_uncle_of
child_in_law = swap (project_first_and_third_of_3 (join_second_of_2_with_first_of_2 parent_of married_to))

|| ancestor_of (Hint - use make_transitive and parent_of
ancestor_of = ((make_transitive parent_of) -- parent_of) -- grandparent

|| brother_or_sister_of (Hint - similar to grandparent but 
||     a different join of parent_of with itself, followed by a project)
brother_or_sister_of = remove_reflexives (project_first_and_third_of_3 (join_second_of_2_with_first_of_2 child_of parent_of))

|| sister_of
sister_of = join_first_of_1_with_first_of_2 female brother_or_sister_of 

|| aunty_or_uncle_of
aunty_or_uncle_of = project_first_and_third_of_3 (join_second_of_2_with_first_of_2 brother_or_sister_of parent_of)

|| aunty_or_uncle_of_mary (Hint - do a select operation on the 
|| aunty_or_uncle_of relation
aunty_or_uncle_of_mary = select_second_of_2 aunty_or_uncle_of "mary"

|| neice_of
neice_of = join_first_of_1_with_first_of_2 female neice_or_nephew

|| cousin_of
cousin_of = project_second_and_third_of_3 (join_first_of_2_with_first_of_2 aunty_or_uncle_of parent_of) 

|| daughter_in_law_of
daughter_in_law_of = join_first_of_1_with_first_of_2 female child_in_law

|| grandparent_of_bill
grandparent_of_bill = select_second_of_2 grandparent "bill"

|| You need to define some additional relational algebra
|| operators similar to those above. For example,
|| you may need an operator join_first_of_2_with_first_of_2

|| It would also help to define
|| an operator called "swap" which takes a binary relation
|| and swaps the columns. Then you can define "child_of"
|| as "swap parent_of" etc. (hint - use map to define swap)
||
|| You should also define an operator which takes a binary relation 
|| removes all tuples which contain the same value in both fields
|| Here is one possible definition:

remove_reflexives r = [(x, y) | (x, y) <- r; x ~= y]

||NOTES

|| This assignment is intended to give you an understanding of relational algebra.
|| Each of your programs must be defined using a combination of relational
|| algebra operators chosen from select, project, join, union, intersection 
|| (and make-transitive and remove_refexives.

|| You should not use recursion in your programs, nor should you define
|| the new relations "sister_of" etc. by listing the contents, or by 
|| using list comprehensions.

|| You can use list comprehensions to define new relational algebra 
|| operators that you need.

|| In order to determine which relational algebra operators are needed 
|| for each new relation, you should draw tables
|| to represent the given data (male, female, parent_of, married_to)
|| and then draw more tables that can be generated from the original tables 
|| using relational algebra operators, until you can generate the required table.
|| Examples will be given in class, and at the group assignment the week 
|| before the due date for this assignment.



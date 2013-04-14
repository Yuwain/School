 || Group ASSIGNMENT #4  
|| You must work as a group on this assignment. Either use a 
|| single laptop, or go to the Java lab and use a single Sunray 
|| Terminal. Download this file from the course website
||
|| under group assignments -> group_assig_4.m
||
|| and experiment with it. Try using the programs
|| from PART II of this file. Then write the programs as 
|| stated in PART III at the end of the second page.
||
|| PART I
|| The following is the data for this assignment

metal     = ["bolt", "nut", "washer", "bearing", "cog", "newnut"]
plastic   = ["gasket", "clip", "strap", "spacer", "newclip"]
part          = metal ++ plastic
compound_part = ["c1", "c2", "c3", "c4", "c5", "c6", "c7"]
component     = part ++ compound_part

component_of = [("bolt","c1"), ("nut", "c1"), ("washer", "c1"),
                ("bearing", "c2"), ("cog", "c2"), ("gasket", "c2"),
                ("clip", "c3"), ("strap", "c3"), ("spacer", "c3"),
                ("c1", "c4"), ("c3", "c4"), ("c4", "c5"), 
                ("c2", "c5"), ("c5", "c6")]
	   
substitute_for = [("newnut", "nut"), ("newclip", "clip")] 

|| The following are example programs for relational algebra 
|| You will need to add some operators similar to these
	    
project_first_of_2 r = mkset[(x) | (x, y) <- r]

project_second_of_2 r = mkset[(y) | (x, y) <- r]

project_first_and_third_of_3 r = mkset[(x,z) | (x,y,z) <- r]

project_second_and_third_of_3 r = mkset[(y, z) | (x, y, z) <- r]
join_first_of_2_with_first_of_2 r s
      = [(x, y, z) | (x, y) <- r; (a , z) <- s; x = a]

join_first_of_1_with_first_of_2 r s
      = [(x, y) | (x) <- r; (a , y) <- s; x = a]

join_second_of_2_with_first_of_2 r s
      = [(x, y, z) | (x, y) <- r; (a , z) <- s; y = a]


select_second_of_2 r key = [(x,y) | (x, y) <- r; y = key]

select_first_of_2 r key = [(x,y) | (x, y) <- r; x = key]

remove_reflexives r = [(a, b) | (a, b) <- r; a ~= b]

swap = map switch
       where switch (a, b) = (b, a)

union s t = s ++ (t --s)

intersection s t = s -- (s -- t)

make_transitive [] = []
make_transitive ((x, y):ps)
  = new_direct_paths ++
    [(a,c) | (a,b) <- mtps; (d,c) <- new_direct_paths; b = d] ++ mtps
    where
    mtps = make_transitive ps
    new_direct_paths = (x, y):[(x, b) | (n, b) <- mtps; n = y]

|| PART II
|| Now consider the following new relations that can be defined
|| in terms of the relations above
|| try these relations by typing their name at the mira prompt

sub_component_of  
   = project_first_and_third_of_3
      (join_second_of_2_with_first_of_2 component_of component_of)      

all_parts_of = make_transitive component_of

uses_component = swap component_of

used_together_with 
   = remove_reflexives 
      (project_second_and_third_of_3
        (join_first_of_2_with_first_of_2 uses_component 
	                                       uses_component))

sub_component_of_c5 
  = project_first_of_2
      (select_second_of_2 sub_component_of "c5")

|| PART III  Now write definitions for the following relations
|| all_parts_of_c5
|| all_parts_used_in_c5_but_not_in_c4
|| plastic_parts_of_c5
|| all_compound_parts_which_use_a_bolt
|| parts_which_are_used_together_with_a_bolt

all_parts_of_c5 = project_first_of_2 (select_second_of_2 all_parts_of "c5") -- compound_part

all_parts_of_c4 = project_first_of_2 (select_second_of_2 all_parts_of "c4") -- compound_part
all_parts_used_in_c5_but_not_in_c4 = all_parts_of_c5 -- all_parts_of_c4

plastic_parts_of_c5 = all_parts_of_c5 -- metal

all_compound_parts_which_use_a_bolt = project_second_of_2 (select_first_of_2 all_parts_of "bolt")

parts_which_are_used_together_with_a_bolt = project_first_of_2 (select_second_of_2 used_together_with "bolt")

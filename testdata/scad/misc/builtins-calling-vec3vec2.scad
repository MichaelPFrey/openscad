//Various lengths
cube();
cube([1]);
cube([1,2]);
cube([1,2,3]); //I'm fine
cube([1,2,3,4]);

//not numbers
cube([1,"test",3]); 
cube([1,"2",3]);
cube(["1.2","2",3]); 

square([1]);
square([1,2]); //I'm fine
square([1,2,3]);

mirror(1)
mirror([1,2])//I'm fine
mirror([1,2,3])//I'm fine
mirror([1,2,3,4])
scale(1)//I'm fine
scale([1])
scale([1,2])  //I'm fine
scale([1,2,3])//I'm fine
scale([1,2,3,4])
cube([3,2,1]); //I'm fine
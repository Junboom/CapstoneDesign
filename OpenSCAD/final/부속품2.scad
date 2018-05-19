rotate(a=90,v=[0,1,0]) {
difference() {
    union() {
        translate([138,60,80])
        rotate(a=90,v=[0,1,0]) {
            cylinder(r=60,h=2,$fn=50); // front
        }
        translate([138,60,80])
        cube([2,65,60]);  // front2
    }
    
    union() {
        translate([20,0,20])
        cube([195,260,60]); // inside bottom
        
        translate([20,10,60])
        cube([113,130,27]); // inside printer
        translate([20,140,60])
        cube([195,130,61]); // inside lcd
        
        translate([45,266,20])
        cube([145,25,101]); // inside back lid
        translate([45,266,10])
        cube([145,10,11]);  // inside bottom lid
        
        translate([140,-1,-1])
        cube([96,292,142]);
        translate([-1,122,-1])
        cube([141,169,142]);
        
        translate([125,10,60])
        cube([9,131,27]);   // 133+7,10+130,60+27
        
        translate([135,50,6.9])
        cube([6,20,6.2]);    // in
    }
}

difference() {
    union() {
        translate([130,122,89])
        rotate(a=90,v=[0,1,0]) {
            cylinder(r=29.8,h=9,$fn=25);
        }
    }
    
    union() {
        translate([20,10,20])
        cube([195,260,40]); // inside bottom
        
        translate([20,10,60])
        cube([113,130,27]); // inside printer
        translate([20,140,60])
        cube([195,130,61]); // inside lcd
        
        translate([45,266,20])
        cube([145,25,101]); // inside back lid
        translate([45,266,10])
        cube([145,10,11]);  // inside bottom lid
        
        translate([140,-1,-1])
        cube([96,292,142]);
        translate([-1,122,-1])
        cube([141,169,142]);
        
        translate([132,10,60])
        cube([9,131,27]);   // 133+7,10+130,60+27
        
        translate([135,50,6.9])
        cube([6,20,6.2]);    // in
    }
}
}

difference() {
    union() {
        difference() {
            cube([235,290,80]); // bottom
            
            union() {
                translate([168,20,78])
                cube([53,74,3]);    // nfc
                translate([180,94,78])
                cube([29,35,3]);    // nfc module
                translate([187,122,78])
                cube([14,20,3]);    // nfc line
                
                translate([50,-1,30])
                cube([57,11,5]);    // printer
            }
        }
        
        translate([0,60,80])
        rotate(a=90,v=[0,1,0]) {
            cylinder(r=60,h=140,$fn=50);    // front
        }
        
        difference() {
            translate([0,60,80])
            cube([140,65,60]);  // front2
        }
        
        difference() {
            translate([0,122,80])
            cube([235,168,60]); // back
            
            union() {
                translate([187,122,79])
                cube([14,20,6]);    // nfc line
                
                translate([21,140,138])
                cube([193,112,3]);  // lcd
                translate([33,147,134])
                cube([167,101,5]);  // lcd bottom
                translate([79,164,120])
                cube([65,56,15]);   // lcd module
                translate([98,220,130])
                cube([40,32,10]);    // lcd line
                
                translate([45,266,120])
                cube([145,10,21]);  // back lid
            }
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
        
    }
}

translate([45,266,160])
difference() {
    cube([144,9,170]);
    
    union() {
        translate([72,-1,150])
        rotate(a=90,v=[-1,0,0]) {
            cylinder(r=10,h=11,$fn=50);
        }
        
        translate([108,-1,50])
        rotate(a=90,v=[-1,0,0]) {
            cylinder(r=14,h=11,$fn=50);
        }
        
        translate([96,-1,38])
        rotate(a=90,v=[-1,0,0]) {
            cylinder(r=1,h=11,$fn=50);
        }
        translate([96,-1,62])
        rotate(a=90,v=[-1,0,0]) {
            cylinder(r=1,h=11,$fn=50);
        }
        translate([120,-1,62])
        rotate(a=90,v=[-1,0,0]) {
            cylinder(r=1,h=11,$fn=50);
        }
        translate([120,-1,38])
        rotate(a=90,v=[-1,0,0]) {
            cylinder(r=1,h=11,$fn=50);
        }
        
        translate([20,-1,10])
        cube([30,11,15]);
    }
}

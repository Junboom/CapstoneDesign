rotate(a=90,v=[0,-1,0]) {
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
                translate([35,143,131])
                cube([167,103,8]);  // lcd bottom
                translate([90,171,120])
                cube([65,58,15]);   // lcd module
                translate([97,140,127])
                cube([44,32,13]);    // lcd line
                translate([136,228,120])
                cube([5,18,15]);
                
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
        translate([20,120,60])
        cube([195,150,61]); // inside lcd
        
        translate([45,266,20])
        cube([145,25,101]); // inside back lid
        translate([139,275,120])
        cube([30,9,21]);    // inside pan
        translate([45,266,10])
        cube([145,10,11]);  // inside bottom lid
        
        translate([140,-1,-1])
        cube([96,292,142]);
        translate([-1,-1,-1])
        cube([141,123,142]);
        
        translate([132,121,60])
        cube([9,20,27]);   // 133+7,122+18,60+27
        
        translate([60,121,125])
        cube([20,7,10]);        // in
    }
}

translate([139,200,7])
cube([6,20,6]);        // on
}

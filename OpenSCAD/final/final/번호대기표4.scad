rotate(a=90,v=[0,1,0]) {
difference() {
    union() {
        difference() {
            cube([235,290,80]); // bottom
            
            union() {
                translate([168,20,78])
                cube([53,74,3]);    // nfc
                translate([180,94,77])
                cube([29,35,4]);    // nfc module
                translate([187,122,77])
                cube([14,20,4]);    // nfc line
                
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
                cube([14,20,6]);    // nfc line2
                
                translate([21,140,138])
                cube([193,112,3]);  // lcd
                translate([35,143,120])
                cube([168,103,20]);  // lcd bottom
                // translate([91,172,120])
                // cube([65,56,15]);   // lcd module
                translate([97,140,130])
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
        translate([139,275,120])
        cube([30,9,21]);    // inside pan
        translate([45,266,10])
        cube([145,10,11]);  // inside bottom lid
        
        translate([-1,-1,-1])
        cube([141,292,142]);
        translate([140,-1,-1])
        cube([96,123,142]);
        
        translate([139,199.8,6.8])
        cube([6,20.4,6.4]);        // in
    }
}
translate([133,122,60])
cube([7,18,61]);   // 133+7,10+130,60+27

translate([170.2,117,6.2])
cube([19.6,6,6.6]);     // on
}

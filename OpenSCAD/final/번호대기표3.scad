rotate(a=90,v=[1,0,0]) {
difference() {
    union() {
        difference() {
            cube([235,290,80]); // bottom
            
            union() {
                translate([168,16,78])
                cube([53,78,3]);    // nfc
                translate([180,13,78])
                cube([29,116,3]);    // nfc module
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
                translate([35,144,134])
                cube([167,101,5]);  // lcd bottom
                translate([91,172,120])
                cube([65,56,15]);   // lcd module
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
        translate([45,266,10])
        cube([145,10,11]);  // inside bottom lid
        
        translate([-1,-1,-1])
        cube([141,292,142]);
        translate([140,122,-1])
        cube([96,169,142]);
        
        translate([170.1,117,6.1])
        cube([19.8,6,6.8]);     // in
    }
}

translate([132,10,60])
cube([8,112,27]);   // 133+7,10+130,60+27

translate([135,50.1,7])
cube([6,19.8,6]);       // on
}

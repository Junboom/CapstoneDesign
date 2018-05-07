rotate(a=90,v=[-1,0,0]) {
difference() {
    cube([144,9,155]);
    
    union() {
        translate([40,0,0])
        union() {
        union() {
            translate([10,-1,145])
            cube([10,11,2]);
            translate([11,-1,137])
            rotate(a=45,v=[0,-1,0]) {
                cube([12,11,2]);
            }
            translate([15,-1,141])
            rotate(a=45,v=[0,1,0]) {
                cube([6,11,2]);
            }
            translate([22,-1,134])
            cube([2,11,15]);
            translate([22,-1,143])
            rotate(a=90,v=[0,1,0]) {
                cube([2,11,5]);
            }
        }
        
        union() {
            translate([40,-1,145])
            rotate(a=90,v=[-1,0,0]) {
                cylinder(r=4,h=11,$fn=50);
            }
            translate([32,-1,138])
            cube([16,11,2]);
            translate([36,-1,133])
            cube([2,11,5]);
            translate([42,-1,133])
            cube([2,11,5]);
        }
        
        union() {
            translate([55,-1,137])
            rotate(a=30,v=[0,1,0]) {
                cube([2,11,12]);
            }
            translate([64,-1,136])
            rotate(a=40,v=[0,-1,0]) {
                cube([2,11,8]);
            }
            translate([68,-1,134])
            cube([2,11,15]);
        }
        
        union() {
            translate([78,-1,145])
            cube([9,11,2]);
            translate([85,-1,139])
            rotate(a=75,v=[0,-1,0]) {
                cube([7,11,2]);
            }
            translate([89,-1,139])
            cube([2,11,9]);
            translate([89,-1,142])
            cube([5,11,2]);
            translate([81,-1,132])
            cube([2,11,6]);
            translate([81,-1,132])
            cube([11,11,2]);
        }
    }
        
        // translate([72,-1,140])
        // rotate(a=90,v=[-1,0,0]) {
        //     cylinder(r=10,h=11,$fn=50);
        // }
        
        translate([108,-1,50])
        rotate(a=90,v=[-1,0,0]) {
            cylinder(r=14,h=11,$fn=50);
        }
        
        translate([96,-1,38])
        rotate(a=90,v=[-1,0,0]) {
            cylinder(r=1.2,h=11,$fn=50);
        }
        translate([96,-1,62])
        rotate(a=90,v=[-1,0,0]) {
            cylinder(r=1.2,h=11,$fn=50);
        }
        translate([120,-1,62])
        rotate(a=90,v=[-1,0,0]) {
            cylinder(r=1.2,h=11,$fn=50);
        }
        translate([120,-1,38])
        rotate(a=90,v=[-1,0,0]) {
            cylinder(r=1.2,h=11,$fn=50);
        }
        
        translate([20,-1,-1])
        cube([30,11,26]);
    }
}

translate([80,0,146])
rotate(a=45,v=[0,1,0]) {
    cube([1,9,4]);
}
translate([80,0,145])
rotate(a=90,v=[-1,0,0]) {
    cylinder(r=2,h=9,$fn=50);
}
}

rotate(a=90,v=[1,0,0])
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
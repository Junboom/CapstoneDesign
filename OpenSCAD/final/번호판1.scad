difference() {
    union() {
        cube([124,108,18]);
        
        
    }
    
    translate([4,4,2])
    cube([121,85,14]);      // in
    
    translate([20,11.8,16])
    cube([105,63.4,3]);     // switch
    
    translate([23,78,16])
    cube([8,2,3]);          // LED
    
    translate([34,4,16])
    cube([121,85,3]);      // module
    
    translate([65,-1,6])
    cube([17,6,13]);       // serial
}

difference() {
    translate([34,4,16])
    rotate(a=60,v=[0,-1,0]) {
        cube([60,100,4]);
    }
    
    translate([20,11.8,16])
    cube([105,63.4,9]);      // switch
    
    translate([20,0,18]);
    //cube([
}

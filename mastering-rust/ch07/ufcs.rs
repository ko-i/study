trait Driver {
    fn drive(&self) {
        println!("Drivers's driving!");
    }
}

struct MyCar;

impl MyCar {
    fn drive(&self) {
        println!("I'm driving!");
    }
}

impl Dirver for MyCar {}

fn main() {
    let car = MyCar;
    car.drive()
    // Driver::drive(&car);
}
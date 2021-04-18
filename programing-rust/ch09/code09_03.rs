use std::cell::Cell;
use std::cell::RefCell;

pub struct SpiderRobot {
    species: String,
    web_enabled: bool,
    leg_devices: [fd::FileDesc; 8],
    hardware_error_count: Cell<u32>,
    log_file: RefCell<File>,
}

use std::rc::Rc;

pub struct SpiderSenses {
    robot: Rc<SpiderRobot>,
    eyes: [Camera; 32],
    motion: Accelerometer,
}

impl SpiderRobot {
    pub fn add_hardware_error(&self) {
        let n = self.hardware_error_count.get();
        self.hardware_error_count.set(n + 1);
    }

    pub fn has_hardware_errors(&self) -> bool {
        self.hardware_error_count.get() > 0
    }

    pub fn log(&self, message: &str) {
        let mut file = self.log_file.borrow_mut();
        writeln!(file, "{}", message).unwrap();
    }
}

fn main() {
    let ref_cell: RefCell<String> = RefCell::new("hello".to_string());

    let r = ref_cell.borrow();
    let count = r.len();
    println!("{:?}", count);

    let mut w = ref_cell.borrow_mut();
    w.push_str(" world");
    println!("{:?}", w);
}
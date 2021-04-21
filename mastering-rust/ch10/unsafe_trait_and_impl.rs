struct MyType;

unsafe trait UnsafeTrait {
    unsafe fn unsafe_func(&self);
    fn safe_func(&self) {
        println!("Things are fine here");
    }
}

trait SafeTrait {
    unsafe fn look_before_you_call(&self);
}

unsafe impl UnsafeTrait for MyType {
    unsafe fn unsafe_func(&self) {
        println!("Highly unsafe");
    }
}

impl SafeTrait for MyType {
    unsafe fn look_before_you_call(&self) {
        println!("Something unsafe");
    }
}

fn main() {
    let my_type = MyType;
    my_type.safe_func();
    unsafe {
        my_type.look_before_you_call();
    }
}
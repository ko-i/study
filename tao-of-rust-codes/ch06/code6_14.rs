fn hello() {
    println!("hello function pointer");
}

fn main() {
    let fn_ptr: fn() = hello;

    println!("{:p}", fn_ptr);

    let other_fn = hello;
    // println!("{:p}", other_fn);

    hello();
    other_fn();
    fn_ptr();
    (fn_ptr)();
}
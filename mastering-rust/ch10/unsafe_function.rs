unsafe fn get_value(i: *const i32) -> i32 {
    *i
}

fn main() {
    let foo = &1024 as *const i32;
    let _bar = unsafe { get_value(foo) };
}
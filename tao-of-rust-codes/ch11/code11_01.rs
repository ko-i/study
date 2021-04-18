static mut V: i32 = 0;

fn unsafe_seq() -> i32 {
    unsafe {
        V += 1
        V
    }
}
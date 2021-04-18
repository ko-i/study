use std::slice;

fn main() {
    let address = 0x01234usize;
    let r = address as *mut 32;

    let slice: &[i32] = unsafe {
        slice::from_raw_parts_mut(r, 10000)
    };
}

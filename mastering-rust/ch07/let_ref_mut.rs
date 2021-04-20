#[derive(Debug)]
struct Items(u32);

fn main() {
    let items = Items(2);
    let items_ptr = &items;
    let ref items_ref = items;

    assert_eq!(items_ptr as *const Items, items_ref as *const Items);

    let mut a = Items(20);
    {
        let ref mut b = a;  // same as let b = &mut a;
        b.0 += 25;
    }

    println!("{:?}", items);
    println!("{:?}", a);
}
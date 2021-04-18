use std::fmt::Debug;

fn dump<T, U>(t: T) where T: IntoIterator<Item = U>, U: Debug {
    for u in t {
        println!("{:?}", u);
    }
}
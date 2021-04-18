use std::sync::RwLock;

fn main() {
    let lock = RwLock::new(5);

    {
        let r1 = lock.read().unwrap();
        let r2 = lock.read().unwrap();

        println!("{:?}", *r1);
        println!("{:?}", *r2);
    }

    {
        let mut w = lock.write().unwrap();
        *w += 1;

        println!("{:?}", *w);
    }
}
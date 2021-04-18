trait InIterator<T: Copy> {
    fn each<F: Fn(T) -> T>(&mut self, f: F);
}

impl<T> InIterator<T> for Vec<T> where T: Copy {
    fn each<F: Fn(T) -> T>(&mut self, f: F) {
        let mut i = 0;

        while i < self.len() {
            self[i] = f(self[i]);

            i += 1;
        }
    }
}

fn main() {
    let mut v = vec![1, 2, 3];
    v.each(|i| i * 3);

    println!("{:?}", v);
}
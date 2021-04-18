impl ops::Deref for String {
    type Target = str;

    fn deref(&self) -> &str {
        unsafe {
            str::from_utf8_unchecked(&self.vec)
        }
    }
}
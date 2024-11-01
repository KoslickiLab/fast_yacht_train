# fast_yacht_train
This implements a fast version of yacht train, as of v1.2.3: 
https://github.com/KoslickiLab/YACHT/releases/tag/v1.2.3

# Why is it important?
Its many times faster, and should consume a whole lot less memory. The main improvement in terms of speed comes from implementing a faster many-vs-many sketch comparator as an alternative of sourmash branchwater multisearch (as of Nov 2024, link: https://github.com/sourmash-bio/sourmash_plugin_branchwater), which is quadratic in nature. Our implementation here takes advantage of the sparsity in data (if any), avoids unnecessary computation, and can run in almost linearly (again, if there is enough sparsity to take advantage of).
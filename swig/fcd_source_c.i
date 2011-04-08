/*
 * First arg is the package prefix.
 * Second arg is the name of the class minus the prefix.
 *
 * This does some behind-the-scenes magic so we can
 * access fcd_source_c from python as fcd.source_c
 */
GR_SWIG_BLOCK_MAGIC(fcd,source_c);

fcd_source_c_sptr fcd_make_source_c ();

class fcd_source_c : public gr_hier_block2
{
private:
  fcd_source_c ();
};

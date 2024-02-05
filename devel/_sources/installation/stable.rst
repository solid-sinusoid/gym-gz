.. _installation_stable:

Stable
======

The stable channel is the easiest way to setup your system.
As described in the :ref:`support policy <support_policy>`, this channel allows installing Gz from binary packages.

We publish updated stable packages after any tagged release of the ``master`` branch.

.. include:: virtual_environment.rst

PyPI Package
************

We provide two different packages for ScenarIO and gym-gz.

If you are interested in the ScenarIO package,
install the `scenario <https://pypi.org/project/scenario/>`_ package from PyPI:

.. code-block:: bash

   pip install scenario

Instead, if you are interested in gym-gz,
install the `gym-gz <https://pypi.org/project/gym-gz/>`_ package from PyPI:

.. code-block:: bash

   pip install gym-gz

It will download and install also ``scenario`` since it depends on it.

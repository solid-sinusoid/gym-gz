.. _what_is_gym_gz:

What is gym-gz?
=====================

**gym-gz** is a framework to create **reproducible robotics environments** for reinforcement learning research.

It is based on the :ref:`ScenarIO <what_is_scenario>` project which provides the low-level APIs to interface with the Gz sim simulator.
By default, RL environments share a lot of boilerplate code, e.g. for initializing the simulator or structuring the classes
to expose the ``gym.Env`` interface.
Gym-gz provides the :py:class:`~gym_gz.base.task.Task` and :py:class:`~gym_gz.base.runtime.Runtime`
abstractions that help you focusing on the development of the decision-making logic rather than engineering.
It includes :py:mod:`~gym_gz.randomizers` to simplify the implementation of domain randomization
of models, physics, and tasks.
Gym-gz also provides powerful dynamics algorithms compatible with both fixed-base and floating-based robots by
exploiting `iDynTree <https://github.com/robotology/idyntree/>`_ and exposing
high-level functionalities (:py:mod:`~gym_gz.rbd.idyntree`).

Gym-gz does not provide out-of-the-box environments ready to be used.
Rather, its aim is simplifying and streamlining their development.
Nonetheless, for illustrative purpose, it includes canonical examples in the
:py:mod:`gym_gz_environments` package.

from setuptools import find_packages
from setuptools import setup

setup(
    name='sample_skill_msgs',
    version='0.1.0',
    packages=find_packages(
        include=('sample_skill_msgs', 'sample_skill_msgs.*')),
)

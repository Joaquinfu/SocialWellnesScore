from setuptools import setup

package_name = 'sws_metrics'

setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Joaquin',
    maintainer_email='joaquin@du.edu',
    description='Social Wellness Score metric nodes for RYAN — DU REU 2026',
    license='MIT',
    entry_points={
        'console_scripts': [
            # Node 1 — built and verified
            'gaze_estimator   = sws_metrics.gaze_estimator:main',
            #Node 0 - Synthetic test data publisher
	    'fake_hri_pub     = sws_metrics.fake_hri_pub:main' ,

            # Node 2 — proximity (add when built)
            # 'proximity_node   = sws_metrics.proximity_node:main',

            # Node 3 — interaction frequency (add when built)
            'interaction_freq = sws_metrics.interaction_freq:main',

            # Node 4 — isolation detection (add when built)
             'isolation_detect = sws_metrics.isolation_detect:main',

             # Node 5 — aggregator (add when all 4 nodes are verif))
             'sws_aggregator   = sws_metrics.sws_aggregator:main',
            # Node 6 — CSV logger (add last)
            # 'csv_logger       = sws_metrics.csv_logger:main',
	    
            # Node 7 - vocal_engagment
	      'vocal_engagement = sws_metrics.vocal_engagement:main',
	    # Node 8 - head_gaze
	      'head_gaze = sws_metrics.head_gaze:main',
        ],
    },
)

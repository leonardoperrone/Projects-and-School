import { AfterContentInit, AfterViewInit, ChangeDetectorRef, EventEmitter, OnInit, QueryList } from '@angular/core';
import { TabComponent } from "./tabpill.component";
export declare class TabPaneComponent implements OnInit, AfterContentInit, AfterViewInit {
    private cdf;
    icons: boolean;
    pills: boolean;
    stacked: boolean;
    closable: boolean;
    tabs: QueryList<TabComponent>;
    onSelect: EventEmitter<{}>;
    selectedTabId: string;
    OPERATION_TOGGLE: string;
    OPERATION_DELETE: string;
    elementId: string;
    constructor(cdf: ChangeDetectorRef);
    ngOnInit(): void;
    ngAfterViewInit(): void;
    ngAfterContentInit(): void;
    loadTab(tabId: string): void;
    removeTab(): void;
    changeActiveTab(tab: TabComponent): void;
    getIconClass(tab: TabComponent): string;
}
